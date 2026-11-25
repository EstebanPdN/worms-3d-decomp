/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_shutdown_800ba5f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8009081c = 0x8009081c;
FUN_800b9a48 = 0x800b9a48;
FUN_800b9b0c = 0x800b9b0c;
SECTIONS {
  .text.s19_shutdown_800ba5f8 0x800ba5f8 : { *(.text.s19_shutdown_800ba5f8) }
  .sdata 0x804aad30 (NOLOAD) : {
    . = 0x0; lbl_804aad30 = .;
    . = 0x3818; lbl_804ae548 = .;
    . = 0x6b0c; lbl_804b183c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
