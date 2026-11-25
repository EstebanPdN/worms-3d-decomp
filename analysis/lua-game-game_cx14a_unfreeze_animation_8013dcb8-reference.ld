/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_unfreeze_animation_8013dcb8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
play_801359ec = 0x801359ec;
rate_8039fb68 = 0x8039fb68;
release_800a4cd0 = 0x800a4cd0;
resolve_80164fc8 = 0x80164fc8;
zero_8039fb6c = 0x8039fb6c;
SECTIONS {
  .text.w3d_cx14a_unfreeze_animation_8013dcb8 0x8013dcb8 : { *(.text.w3d_cx14a_unfreeze_animation_8013dcb8) }
  .sdata 0x804ab1e0 (NOLOAD) : {
    . = 0x0; name_804ab1e0 = .;
    . = 0x4; name_804ab1e4 = .;
    . = 0x8; name_804ab1e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
