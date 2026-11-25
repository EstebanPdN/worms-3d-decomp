#!/bin/zsh
set -eu
port_dir=${0:A:h}
app="$port_dir/build/Worms 3D.app"
mkdir -p "$app/Contents/MacOS"
install -m 755 "$port_dir/build/worms3d" "$app/Contents/MacOS/worms3d"
mkdir -p "$app/Contents/Resources/ui"
cp "$port_dir"/platform/macos/ui/*.w3ui "$app/Contents/Resources/ui/"
strip -S "$app/Contents/MacOS/worms3d"
cat > "$app/Contents/Info.plist" <<'PLIST'
<?xml version="1.0" encoding="UTF-8"?>
<plist version="1.0"><dict>
<key>CFBundleName</key><string>Worms 3D</string>
<key>CFBundleIdentifier</key><string>io.github.estebanpdn.worms3d.mac</string>
<key>CFBundleExecutable</key><string>worms3d</string>
<key>CFBundlePackageType</key><string>APPL</string>
<key>CFBundleVersion</key><string>1</string>
<key>CFBundleShortVersionString</key><string>0.1</string>
<key>LSMinimumSystemVersion</key><string>27.0</string>
</dict></plist>
PLIST
codesign --force --sign - "$app"
ditto -c -k --keepParent --norsrc --noextattr "$app" "$port_dir/build/Worms-3D-macOS-arm64.zip"
