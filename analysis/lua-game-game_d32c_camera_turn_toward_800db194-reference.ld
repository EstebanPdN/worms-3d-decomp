/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32c_camera_turn_toward_800db194)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
axis_801f6480 = 0x801f6480;
damp_800dbd74 = 0x800dbd74;
norm_801f6c2c = 0x801f6c2c;
smooth_800dc0b4 = 0x800dc0b4;
sqrt_802e82c0 = 0x802e82c0;
steer_800dbda8 = 0x800dbda8;
turn_800dbd58 = 0x800dbd58;
view_8015aa04 = 0x8015aa04;
SECTIONS {
  .text.d32c_camera_turn_toward_800db194 0x800db194 : { *(.text.d32c_camera_turn_toward_800db194) }
  .rodata 0x8038983c : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; camera_804aa8c8 = .;
    . = 0x6ec0; svc_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
