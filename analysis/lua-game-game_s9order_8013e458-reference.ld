/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_auto_80189190)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8017B348 = 0x8017b348;
SECTIONS {
  .text.s9_auto_80189190 0x80189190 : { *(.text.s9_auto_80189190) }
  .sdata 0x804ab698 (NOLOAD) : {
    . = 0x0; lbl_804AB698 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
