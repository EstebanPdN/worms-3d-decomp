/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f5a_setup_pointer_8026f6e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
factory_8041c220 = 0x8041c220;
fn_80164514 = 0x80164514;
fn_8020b680 = 0x8020b680;
fn_8026ed00 = 0x8026ed00;
fn_80295268 = 0x80295268;
fn_80295468 = 0x80295468;
fn_8029550c = 0x8029550c;
fn_8029623c = 0x8029623c;
fn_80296298 = 0x80296298;
fn_80296518 = 0x80296518;
fn_80296774 = 0x80296774;
fn_8029677c = 0x8029677c;
scale_803cbf1c = 0x803cbf1c;
zero_803cbf20 = 0x803cbf20;
SECTIONS {
  .text.w3d_f5a_setup_pointer_8026f6e0 0x8026f6e0 : { *(.text.w3d_f5a_setup_pointer_8026f6e0) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
