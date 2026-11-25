/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(water_surface_update_800c88c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
as_value_80342a74 = 0x80342a74;
inverse_801f69ec = 0x801f69ec;
lbl_80387af8 = 0x80387af8;
lbl_80387b04 = 0x80387b04;
lbl_80387b14 = 0x80387b14;
lbl_8044b688 = 0x8044b688;
read_800fc270 = 0x800fc270;
read_800fc2b0 = 0x800fc2b0;
read_800fc330 = 0x800fc330;
request_8015cd04 = 0x8015cd04;
set_tint_80182178 = 0x80182178;
sqrt_802e82c0 = 0x802e82c0;
tan_802e8988 = 0x802e8988;
value_80178df0 = 0x80178df0;
waves_800c96f0 = 0x800c96f0;
SECTIONS {
  .text.water_surface_update_800c88c8 0x800c88c8 : { *(.text.water_surface_update_800c88c8) }
  .rodata 0x80387b20 : { *(.rodata) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; lbl_804aaabc = .;
    . = 0x6ccc; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
