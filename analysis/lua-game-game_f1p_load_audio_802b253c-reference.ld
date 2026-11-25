/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_load_audio_802b253c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
error_803d7b04 = 0x803d7b04;
fn_8020c510 = 0x8020c510;
fn_802b22e4 = 0x802b22e4;
fn_802b24bc = 0x802b24bc;
SECTIONS {
  .text.w3d_load_audio_802b253c 0x802b253c : { *(.text.w3d_load_audio_802b253c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
