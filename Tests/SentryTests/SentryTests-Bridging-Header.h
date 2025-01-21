#if !TARGET_OS_WATCH
#    import "SentryReachability.h"
#endif // !TARGET_OS_WATCH

#import "SentryDefines.h"
#import "SentryProfilingConditionals.h"

#if SENTRY_HAS_METRIC_KIT
#    import "SentryMetricKitIntegration.h"
#endif // SENTRY_HAS_METRIC_KIT

#if SENTRY_HAS_UIKIT
#    import "MockUIScene.h"
#    import "SentryFramesTracker+TestInit.h"
#    import "SentrySessionReplayIntegration+Private.h"
#    import "SentryUIApplication+Private.h"
#    import "SentryUIApplication.h"
#    import "SentryUIDeviceWrapper.h"
#    import "SentryUIEventTracker.h"
#    import "SentryUIEventTrackerTransactionMode.h"
#    import "SentryUIEventTrackingIntegration.h"
#    import "SentryUIViewControllerPerformanceTracker.h"
#    import "SentryUIViewControllerSwizzling+Test.h"
#    import "SentryUIViewControllerSwizzling.h"
#    import "UIViewController+Sentry.h"
#endif // SENTRY_HAS_UIKIT

#if SENTRY_TARGET_PROFILING_SUPPORTED
#    import "SentryContinuousProfiler+Test.h"
#    import "SentryContinuousProfiler.h"
#    import "SentryLaunchProfiling+Tests.h"
#    import "SentryMetricProfiler.h"
#    import "SentryProfiler+Private.h"
#    import "SentryProfilerDefines.h"
#    import "SentryProfilerMocksSwiftCompatible.h"
#    import "SentryProfilerSerialization+Test.h"
#    import "SentryProfilerSerialization.h"
#    import "SentryProfilerState.h"
#    import "SentryProfilerTestHelpers.h"
#    import "SentryTraceProfiler+Test.h"
#endif // SENTRY_TARGET_PROFILING_SUPPORTED

#import "NSLocale+Sentry.h"
#import "NSMutableDictionary+Sentry.h"
#import "PrivateSentrySDKOnly.h"
#import "Sentry/Sentry-Swift.h"
#import "SentryANRTrackerV1.h"
#import "SentryANRTrackerV2.h"
#import "SentryANRTrackingIntegration.h"
#import "SentryAppStartMeasurement.h"
#import "SentryAppStartTracker.h"
#import "SentryAppStartTrackingIntegration.h"
#import "SentryAppState.h"
#import "SentryAppStateManager.h"
#import "SentryAttachment+Private.h"
#import "SentryAutoBreadcrumbTrackingIntegration+Test.h"
#import "SentryAutoBreadcrumbTrackingIntegration.h"
#import "SentryAutoSessionTrackingIntegration.h"
#import "SentryBooleanSerialization.h"
#import "SentryBreadcrumb+Private.h"
#import "SentryBreadcrumbDelegate.h"
#import "SentryBreadcrumbTracker.h"
#import "SentryByteCountFormatter.h"
#import "SentryClassRegistrator.h"
#import "SentryClient+Private.h"
#import "SentryClient+TestInit.h"
#import "SentryClientReport.h"
#import "SentryConcurrentRateLimitsDictionary.h"
#import "SentryCoreDataSwizzling.h"
#import "SentryCoreDataTracker+Test.h"
#import "SentryCoreDataTrackingIntegration.h"
#import "SentryCrashBinaryImageCache.h"
#import "SentryCrashBinaryImageProvider.h"
#import "SentryCrashC.h"
#import "SentryCrashDebug.h"
#import "SentryCrashDefaultBinaryImageProvider.h"
#import "SentryCrashDefaultMachineContextWrapper.h"
#import "SentryCrashDoctor.h"
#import "SentryCrashInstallationReporter.h"
#import "SentryCrashIntegration+TestInit.h"
#import "SentryCrashIntegration.h"
#import "SentryCrashJSONCodecObjC.h"
#import "SentryCrashMachineContext.h"
#import "SentryCrashMonitor.h"
#import "SentryCrashMonitorContext.h"
#import "SentryCrashMonitor_AppState.h"
#import "SentryCrashMonitor_System.h"
#import "SentryCrashReport.h"
#import "SentryCrashReportSink.h"
#import "SentryCrashReportStore.h"
#import "SentryCrashScopeObserver.h"
#import "SentryCrashStackEntryMapper.h"
#import "SentryCrashUUIDConversion.h"
#import "SentryCrashWrapper.h"
#import "SentryDataCategory.h"
#import "SentryDataCategoryMapper.h"
#import "SentryDateUtil.h"
#import "SentryDateUtils.h"
#import "SentryDebugImageProvider+HybridSDKs.h"
#import "SentryDebugImageProvider+TestInit.h"
#import "SentryDebugMeta.h"
#import "SentryDefaultObjCRuntimeWrapper.h"
#import "SentryDefaultRateLimits.h"
#import "SentryDependencyContainer.h"
#import "SentryDiscardReason.h"
#import "SentryDiscardReasonMapper.h"
#import "SentryDiscardedEvent.h"
#import "SentryDispatchFactory.h"
#import "SentryDispatchQueueWrapper.h"
#import "SentryDispatchSourceWrapper.h"
#import "SentryDisplayLinkWrapper.h"
#import "SentryDsn.h"
#import "SentryEnvelope+Private.h"
#import "SentryEnvelopeAttachmentHeader.h"
#import "SentryEnvelopeItemType.h"
#import "SentryEnvelopeRateLimit.h"
#import "SentryEvent+Private.h"
#import "SentryExtraContextProvider.h"
#import "SentryFileIOTracker.h"
#import "SentryFileIOTrackingIntegration.h"
#import "SentryFileManager+Test.h"
#import "SentryFileManager.h"
#import "SentryFormatter.h"
#import "SentryFrame.h"
#import "SentryFrameRemover.h"
#import "SentryFramesTrackingIntegration.h"
#import "SentryGlobalEventProcessor.h"
#import "SentryHttpDateParser.h"
#import "SentryHttpStatusCodeRange+Private.h"
#import "SentryHttpTransport.h"
#import "SentryHub+Private.h"
#import "SentryHub+Test.h"
#import "SentryInAppLogic.h"
#import "SentryInitializeForGettingSubclassesNotCalled.h"
#import "SentryInstallation+Test.h"
#import "SentryInstallation.h"
#import "SentryInternalNotificationNames.h"
#import "SentryInvalidJSONString.h"
#import "SentryLevelMapper.h"
#import "SentryLog.h"
#import "SentryLogTestHelper.h"
#import "SentryMeasurementValue.h"
#import "SentryMechanism.h"
#import "SentryMechanismMeta.h"
#import "SentryMeta.h"
#import "SentryMigrateSessionInit.h"
#import "SentryMsgPackSerializer.h"
#import "SentryNSDataUtils.h"
#import "SentryNSError.h"
#import "SentryNSNotificationCenterWrapper.h"
#import "SentryNSProcessInfoWrapper.h"
#import "SentryNSTimerFactory.h"
#import "SentryNSURLRequest.h"
#import "SentryNSURLRequestBuilder.h"
#import "SentryNSURLSessionTaskSearch.h"
#import "SentryNetworkTracker.h"
#import "SentryNetworkTrackingIntegration.h"
#import "SentryNoOpSpan.h"
#import "SentryObjCRuntimeWrapper.h"
#import "SentryOptions+HybridSDKs.h"
#import "SentryOptions+Private.h"
#import "SentryPerformanceTracker+Testing.h"
#import "SentryPerformanceTracker.h"
#import "SentryPerformanceTrackingIntegration.h"
#import "SentryPredicateDescriptor.h"
#import "SentryPropagationContext.h"
#import "SentryQueueableRequestManager.h"
#import "SentryRateLimitParser.h"
#import "SentryRateLimits.h"
#import "SentryReachability.h"
#import "SentryRetryAfterHeaderParser.h"
#import "SentrySDK+Private.h"
#import "SentrySDK+Tests.h"
#import "SentrySampleDecision+Private.h"
#import "SentryScope+Private.h"
#import "SentryScopeObserver.h"
#import "SentryScopeSyncC.h"
#import "SentryScreenFrames.h"
#import "SentryScreenshot.h"
#import "SentryScreenshotIntegration.h"
#import "SentrySwift.h"
#import "SentrySwiftAsyncIntegration.h"
#import "SentryUncaughtNSExceptions.h"

#import "Sentry/Sentry-Swift.h"
#import "SentryBinaryImageCache+Private.h"
#import "SentryCrashBinaryImageCache.h"
#import "SentryDispatchFactory.h"
#import "SentryDispatchSourceWrapper.h"
#import "SentryEnvelopeAttachmentHeader.h"
#import "SentryExtraContextProvider.h"
#import "SentryMeasurementValue.h"
#import "SentryNSProcessInfoWrapper.h"
#import "SentryPerformanceTracker+Testing.h"
#import "SentryPropagationContext.h"
#import "SentrySampleDecision+Private.h"
#import "SentrySerialization.h"
#import "SentrySession+Private.h"
#import "SentrySessionTracker.h"
#import "SentrySpan.h"
#import "SentrySpanId.h"
#import "SentrySpotlightTransport.h"
#import "SentryStacktrace.h"
#import "SentryStacktraceBuilder.h"
#import "SentrySubClassFinder.h"
#import "SentrySwift.h"
#import "SentrySwiftAsyncIntegration.h"
#import "SentrySwizzleWrapper.h"
#import "SentrySysctl.h"
#import "SentrySystemEventBreadcrumbs.h"
#import "SentrySystemWrapper.h"
#import "SentryTestIntegration.h"
#import "SentryTestObjCRuntimeWrapper.h"
#import "SentryThread.h"
#import "SentryThreadInspector.h"
#import "SentryThreadWrapper.h"
#import "SentryTime.h"
#import "SentryTimeToDisplayTracker.h"
#import "SentryTracer+Private.h"
#import "SentryTracer+Test.h"
#import "SentryTracerConfiguration.h"
#import "SentryTransaction.h"
#import "SentryTransactionContext+Private.h"
#import "SentryTransport.h"
#import "SentryTransportAdapter.h"
#import "SentryTransportFactory.h"
#import "SentryUserFeedback.h"
#import "SentryViewHierarchy.h"
#import "SentryViewHierarchyIntegration.h"
#import "SentryWatchdogTerminationLogic.h"
#import "SentryWatchdogTerminationScopeObserver.h"
#import "SentryWatchdogTerminationTracker.h"
#import "SentryWatchdogTerminationTrackingIntegration.h"
#import "TestNSURLRequestBuilder.h"
#import "TestSentryCrashWrapper.h"
#import "TestSentrySpan.h"
#import "TestSentryViewHierarchy.h"
#import "URLSessionTaskMock.h"
@import _SentryPrivate;
#import "SentryCrash+Test.h"
#import "SentryCrashCachedData.h"
#import "SentryCrashInstallation+Private.h"
#import "SentryCrashMachineContext_Apple.h"
#import "SentryCrashMonitor_MachException.h"
#import "SentryCrashStackCursor_Backtrace.h"
#import "SentrySessionReplaySyncC.h"
