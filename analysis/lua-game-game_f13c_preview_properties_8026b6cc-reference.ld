/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f13c_preview_properties_8026b6cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__23F13cSelectFrom_8020bb54PCc = 0x8020bb54;
__26F13cSelectDefault_803426b8 = 0x803426b8;
border_803cba00 = 0x803cba00;
fn_800fc1b0 = 0x800fc1b0;
fn_8015adf4 = 0x8015adf4;
fn_801712c4 = 0x801712c4;
fn_80178df0 = 0x80178df0;
fn_8020bb2c = 0x8020bb2c;
fn_8020bd38 = 0x8020bd38;
fn_8020c2e8 = 0x8020c2e8;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_8026d8e8 = 0x8026d8e8;
fn_802ef234 = 0x802ef234;
fn_802ef9c0 = 0x802ef9c0;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_80342a74 = 0x80342a74;
fn_8034357c = 0x8034357c;
fn_80343808 = 0x80343808;
info_803cbacc = 0x803cbacc;
missing_803cbaa8 = 0x803cbaa8;
mission_803cba60 = 0x803cba60;
suffix_803cba58 = 0x803cba58;
two_803cbadc = 0x803cbadc;
zero_803cbad8 = 0x803cbad8;
SECTIONS {
  .text.w3d_f13c_preview_properties_8026b6cc 0x8026b6cc : { *(.text.w3d_f13c_preview_properties_8026b6cc) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; instance_804abb7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
