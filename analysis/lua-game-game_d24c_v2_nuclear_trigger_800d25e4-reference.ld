/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_v2_nuclear_trigger_800d25e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
assert_80022e20 = 0x80022e20;
file_80388b48 = 0x80388b48;
fn_8002ae70 = 0x8002ae70;
fn_800d2924 = 0x800d2924;
fn_800fdd80 = 0x800fdd80;
identity_80341584 = 0x80341584;
origin_8045e788 = 0x8045e788;
read_800fc1b0 = 0x800fc1b0;
settings_801797b4 = 0x801797b4;
timer_8006e71c = 0x8006e71c;
title_80388b34 = 0x80388b34;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
weapon_803887bc = 0x803887bc;
SECTIONS {
  .text.d24c_v2_nuclear_trigger_800d25e4 0x800d25e4 : { *(.text.d24c_v2_nuclear_trigger_800d25e4) }
  .sdata 0x804aae44 (NOLOAD) : {
    . = 0x0; flag_804aae44 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
