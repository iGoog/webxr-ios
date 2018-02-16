#import <Foundation/Foundation.h>
#import "ARKHelper.h"
#import "AppState.h"

// The ARSessionConfiguration object passed to the run(_:options:) method is not supported by the current device.
#define UNSUPPORTED_CONFIGURATION_ARKIT_ERROR_CODE 100

// A sensor required to run the session is not available.
#define SENSOR_UNAVAILABLE_ARKIT_ERROR_CODE 101

// A sensor failed to provide the required input.
#define SENSOR_FAILED_ARKIT_ERROR_CODE 102

// The user has denied your app permission to use the device camera.
#define CAMERA_ACCESS_NOT_AUTHORIZED_ARKIT_ERROR_CODE 103

// World tracking has encountered a fatal error.
#define WORLD_TRACKING_FAILED_ARKIT_ERROR_CODE 200


typedef NS_ENUM(NSUInteger, ARKType)
{
    ARKMetal,
    ARKSceneKit
};

@class ARKController;
typedef void (^DidUpdate)(ARKController *);
typedef void (^DidFailSession)(NSError *);
typedef void (^DidInterupt)(BOOL);
typedef void (^DidChangeTrackingState)(NSString *state);
typedef void (^DidAddPlaneAnchors)(void);
typedef void (^DidRemovePlaneAnchors)(void);
typedef void (^DidUpdateWindowSize)(void);

@interface ARKController : NSObject

@property(copy) DidUpdate didUpdate;
@property(copy) DidInterupt didInterupt;
@property(copy) DidFailSession didFailSession;
@property(copy) DidChangeTrackingState didChangeTrackingState;
@property(copy) DidAddPlaneAnchors didAddPlaneAnchors;
@property(copy) DidRemovePlaneAnchors didRemovePlaneAnchors;
@property(copy) DidUpdateWindowSize didUpdateWindowSize;
@property UIInterfaceOrientation interfaceOrientation;

@property(nonatomic) BOOL shouldUpdateWindowSize;

- (instancetype)initWithType:(ARKType)type rootView:(UIView *)rootView;
- (UIView *)arkView;

- (void)viewWillTransitionToSize:(CGSize)size;

- (void)startSessionWithAppState:(AppState *)state;

- (void)stopSession;

- (NSDictionary *)arkData;

- (void)resumeSessionWithAppState:(AppState *)state;

- (void)setShowMode:(ShowMode)mode;
- (void)setShowOptions:(ShowOptions)options;

- (NSArray *)hitTestNormPoint:(CGPoint)point types:(NSUInteger)type;
- (BOOL)addAnchor:(NSString *)name transform:(NSArray *)transform;

- (void)removeAnchors:(NSArray *)anchorNames;

- (NSArray *)currentPlanesArray;

- (NSString *)trackingState;
@end

