// swift-tools-version:5.3
import Darwin.C
import PackageDescription

var products: [Product] = [
    .library(name: "Sentry", targets: ["Sentry"]),
    .library(name: "Sentry-Dynamic", targets: ["Sentry-Dynamic"]),
    .library(name: "SentrySwiftUI", targets: ["Sentry", "SentrySwiftUI"])
]

var targets: [Target] = [
    .binaryTarget(
        name: "Sentry",
        url: "https://ddartifacts.jfrog.io/artifactory/swift-general-local/Sentry/8.53.2/Sentry.xcframework.zip",
        checksum: "1f6b32f150a50caf4481ec9962e2fd00ff064b387928b89f683318ac9277db44" //Sentry-Static
    ),
    .binaryTarget(
        name: "Sentry-Dynamic",
        url: "https://ddartifacts.jfrog.io/artifactory/swift-general-local/Sentry/8.53.2/Sentry-Dynamic.xcframework.zip",
        checksum: "ce885f2063c73b8edd0a6a90cb887cee159a9d5f94037c30ca0828ad0bb6e20d" //Sentry-Dynamic
    ),
    .target (
        name: "SentrySwiftUI",
        dependencies: ["Sentry", "SentryInternal"],
        path: "Sources/SentrySwiftUI",
        exclude: ["SentryInternal/", "module.modulemap"],
        linkerSettings: [
            .linkedFramework("Sentry")
        ]),
    .target(
        name: "SentryInternal",
        path: "Sources/SentrySwiftUI",
        sources: [
            "SentryInternal/"
        ],
        publicHeadersPath: "SentryInternal/")
]

let env = getenv("EXPERIMENTAL_SPM_BUILDS")
if let env, String(cString: env, encoding: .utf8) == "1" {
    products.append(.library(name: "SentrySPM", type: .dynamic, targets: ["SentryObjc"]))
    targets.append(contentsOf: [
        // At least one source file is required
        .target(name: "SentryHeaders", path: "Sources/Sentry", sources: ["SentryDsn.m"], publicHeadersPath: "Public"),
        .target(
            name: "_SentryPrivate",
            dependencies: ["SentryHeaders"],
            path: "Sources/Sentry",
            sources: ["NSLocale+Sentry.m"],
            publicHeadersPath: "include",
            cSettings: [.headerSearchPath("include/HybridPublic")]),
        .target(
            name: "SentrySwift",
            dependencies: ["_SentryPrivate", "SentryHeaders"],
            path: "Sources/Swift",
            swiftSettings: [
                // The application extension flag is required due to https://github.com/getsentry/sentry-cocoa/issues/5371
                .unsafeFlags(["-enable-library-evolution", "-Xfrontend", "-application-extension"]),
                // This flag is used to make some API breaking changes necessary for the framework to compile with SPM.
                // We can either make more extensive changes to allow it to be backwards compatible, or release them as part of a V9 release.
                // For now we use this flag so that CI can compile the SPM version.
                    .define("SENTRY_SWIFT_PACKAGE")
            ],
            linkerSettings: [
                .unsafeFlags(["-Xlinker", "-application_extension"])
            ]),
        .target(
            name: "SentryObjc",
            dependencies: ["SentrySwift"],
            path: "Sources",
            exclude: ["Sentry/SentryDsn.m", "Sentry/NSLocale+Sentry.m", "Swift", "SentrySwiftUI", "Resources", "Configuration"],
            cSettings: [
                .headerSearchPath("Sentry/include/HybridPublic"),
                .headerSearchPath("Sentry"),
                .headerSearchPath("SentryCrash/Recording"),
                .headerSearchPath("SentryCrash/Recording/Monitors"),
                .headerSearchPath("SentryCrash/Recording/Tools"),
                .headerSearchPath("SentryCrash/Installations"),
                .headerSearchPath("SentryCrash/Reporting/Filters"),
                .headerSearchPath("SentryCrash/Reporting/Filters/Tools")])
    ])
}

let package = Package(
    name: "Sentry",
    platforms: [.iOS(.v11), .macOS(.v10_13), .tvOS(.v11), .watchOS(.v4)],
    products: products,
    targets: targets,
    cxxLanguageStandard: .cxx14
)
