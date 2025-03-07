// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "Sentry",
    platforms: [.iOS(.v11), .macOS(.v10_13), .tvOS(.v11), .watchOS(.v4)],
    products: [
        .library(name: "Sentry", targets: ["Sentry"]),
        .library(name: "Sentry-Dynamic", targets: ["Sentry-Dynamic"]),
        .library(name: "SentrySwiftUI", targets: ["Sentry", "SentrySwiftUI"])
    ],
    targets: [
        .binaryTarget(
                    name: "Sentry",
                    url: "https://ddartifacts.jfrog.io/artifactory/swift-general-local/Sentry/8.46.0/Sentry.xcframework.zip",
                    checksum: "aaf27ced063c9fcdcddb9ad1e9b63524b21f31165e6e538d35e28c36ef5fca2e" //Sentry-Static
                ),
        .binaryTarget(
                    name: "Sentry-Dynamic",
                    url: "https://ddartifacts.jfrog.io/artifactory/swift-general-local/Sentry/8.46.0/Sentry-Dynamic.xcframework.zip",
                    checksum: "60435d0920f9f0986c087f2f64dc6d09ca553f0945326e8609a1aa727f3f33e9" //Sentry-Dynamic
                ),
        .target ( name: "SentrySwiftUI",
                  dependencies: ["Sentry", "SentryInternal"],
                  path: "Sources/SentrySwiftUI",
                  exclude: ["SentryInternal/", "module.modulemap"],
                  linkerSettings: [
                     .linkedFramework("Sentry")
                  ]
                ),
        .target( name: "SentryInternal",
                 path: "Sources/SentrySwiftUI",
                 sources: [
                    "SentryInternal/"
                 ],
                 publicHeadersPath: "SentryInternal/"
               )
    ],
    cxxLanguageStandard: .cxx14
)
