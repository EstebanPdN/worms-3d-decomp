/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_held_audio_clear_8029d07c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80129738 = 0x80129738;
SECTIONS {
  .text.w3d_k8c_held_audio_clear_8029d07c 0x8029d07c : { *(.text.w3d_k8c_held_audio_clear_8029d07c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; service_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
