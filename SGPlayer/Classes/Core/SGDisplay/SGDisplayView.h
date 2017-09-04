//
//  SGDisplayView.h
//  SGPlayer
//
//  Created by Single on 12/01/2017.
//  Copyright © 2017 single. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "SGPlayerImp.h"
#import "SGAVPlayer.h"
#import "SGFFPlayer.h"
#import "SGImagePlayer.h"

@class SGFingerRotation;
@class SGGLFrame;

typedef NS_ENUM(NSUInteger, SGDisplayRendererType) {
    SGDisplayRendererTypeEmpty,
    SGDisplayRendererTypeAVPlayerLayer,
    SGDisplayRendererTypeOpenGL,
};

typedef NS_ENUM(NSUInteger, SGDisplayPlayerOutputType) {
    SGDisplayPlayerOutputTypeEmpty,
    SGDisplayPlayerOutputTypeFF,
    SGDisplayPlayerOutputTypeAV,
    SGDisplayPlayerOutputTypeIM,
};

@interface SGDisplayView : SGPLFView


+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

+ (instancetype)displayViewWithAbstractPlayer:(SGPlayer *)abstractPlayer;


@property (nonatomic, weak, readonly) SGPlayer * abstractPlayer;
@property (nonatomic, strong, readonly) SGFingerRotation * fingerRotation;


// player output type
@property (nonatomic, assign, readonly) SGDisplayPlayerOutputType playerOutputType;
@property (nonatomic, weak) id <SGFFPlayerOutput> playerOutputFF;
@property (nonatomic, weak) id <SGAVPlayerOutput> playerOutputAV;
@property (nonatomic, weak) id <SGImagePlayerOutput> playerOutputIM;
- (void)playerOutputTypeEmpty;
- (void)playerOutputTypeFF;
- (void)playerOutputTypeAV;
- (void)playerOutputTypeIM;


// renderer type
@property (nonatomic, assign, readonly) SGDisplayRendererType rendererType;
- (void)rendererTypeEmpty;
- (void)rendererTypeAVPlayerLayer;
- (void)rendererTypeOpenGL;


// reload
- (void)reloadGravityMode;
- (void)reloadPlayerConfig;
- (void)reloadVideoFrameForGLFrame:(SGGLFrame *)glFrame;

- (SGPLFImage *)snapshot;

@end
