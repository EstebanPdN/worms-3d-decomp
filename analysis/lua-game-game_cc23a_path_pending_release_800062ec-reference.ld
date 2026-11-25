/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc23a_path_pending_release_800062ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80015264 = 0x80015264;
fn_8034144c = 0x8034144c;
SECTIONS {
  .text.cc23a_path_pending_release_800062ec 0x800062ec : { *(.text.cc23a_path_pending_release_800062ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
