/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f13c_select_preview_8026b3f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__23F13cSelectFrom_8020bb54PCc = 0x8020bb54;
empty_803cba1c = 0x803cba1c;
error_803cb850 = 0x803cb850;
fn_800fc1b0 = 0x800fc1b0;
fn_80179170 = 0x80179170;
fn_801797b4 = 0x801797b4;
fn_8020bb2c = 0x8020bb2c;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_8026a048 = 0x8026a048;
fn_8026b6cc = 0x8026b6cc;
fn_8026b9bc = 0x8026b9bc;
fn_8026c0d0 = 0x8026c0d0;
fn_8026c4dc = 0x8026c4dc;
fn_8026d8a0 = 0x8026d8a0;
fn_802ef234 = 0x802ef234;
fn_80341584 = 0x80341584;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_80343744 = 0x80343744;
random_803cba20 = 0x803cba20;
type_803667a8 = 0x803667a8;
SECTIONS {
  .text.w3d_f13c_select_preview_8026b3f0 0x8026b3f0 : { *(.text.w3d_f13c_select_preview_8026b3f0) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; instance_804abb7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
