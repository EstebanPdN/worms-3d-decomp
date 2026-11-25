#import <AppKit/AppKit.h>

extern "C" char *w3d_choose_data_folder() {
    NSOpenPanel *panel = [NSOpenPanel openPanel];
    panel.message = @"Choose your extracted Worms 3D PAL disc folder (containing sys and files).";
    panel.canChooseFiles = NO;
    panel.canChooseDirectories = YES;
    panel.allowsMultipleSelection = NO;
    if ([panel runModal] != NSModalResponseOK) return nullptr;
    return strdup(panel.URL.fileSystemRepresentation);
}
