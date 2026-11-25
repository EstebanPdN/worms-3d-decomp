/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f10a_rebuild_land_8026d5c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arctic_803cbd64 = 0x803cbd64;
england_803cbd44 = 0x803cbd44;
factory_804103d8 = 0x804103d8;
fn_800f2f94 = 0x800f2f94;
fn_800f339c = 0x800f339c;
fn_800f342c = 0x800f342c;
fn_800f3524 = 0x800f3524;
fn_80164514 = 0x80164514;
fn_8020b680 = 0x8020b680;
fn_8020bd38 = 0x8020bd38;
fn_8020c5c0 = 0x8020c5c0;
fn_8026ce4c = 0x8026ce4c;
fn_8026dbe8 = 0x8026dbe8;
fn_80341884 = 0x80341884;
horror_803cbd54 = 0x803cbd54;
lunar_803cbcf0 = 0x803cbcf0;
pirate_803cbd28 = 0x803cbd28;
war_803cbd38 = 0x803cbd38;
SECTIONS {
  .text.w3d_f10a_rebuild_land_8026d5c0 0x8026d5c0 : { *(.text.w3d_f10a_rebuild_land_8026d5c0) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; root_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
