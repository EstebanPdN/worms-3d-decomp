/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f9b_freeze_effect_8013db60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
angles_800a4d70 = 0x800a4d70;
blend_8039fb60 = 0x8039fb60;
create_80164514 = 0x80164514;
lookup_80164fc8 = 0x80164fc8;
play_801359ec = 0x801359ec;
position_800a4d3c = 0x800a4d3c;
random_80162c20 = 0x80162c20;
rate_8039fb5c = 0x8039fb5c;
start_800a4c70 = 0x800a4c70;
type_8040f558 = 0x8040f558;
typeid_8020b680 = 0x8020b680;
zero_8039fb64 = 0x8039fb64;
SECTIONS {
  .text.f9b_freeze_effect_8013db60 0x8013db60 : { *(.text.f9b_freeze_effect_8013db60) }
  .sdata 0x804ab1d4 (NOLOAD) : {
    . = 0x0; freeze1_804ab1d4 = .;
    . = 0x4; freeze2_804ab1d8 = .;
    . = 0x8; freeze3_804ab1dc = .;
    . = 0x65b8; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
