/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_apply_saved_sound_8028a6c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc230 = 0x800fc230;
fn_800fc43c = 0x800fc43c;
mode_803cfb44 = 0x803cfb44;
SECTIONS {
  .text.w3d_apply_saved_sound_8028a6c0 0x8028a6c0 : { *(.text.w3d_apply_saved_sound_8028a6c0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
