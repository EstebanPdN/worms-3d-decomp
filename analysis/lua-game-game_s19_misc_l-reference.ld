/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_probe_8001744c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80009674 = 0x80009674;
FUN_80009a94 = 0x80009a94;
FUN_8001a02c = 0x8001a02c;
FUN_8001e328 = 0x8001e328;
lbl_8041d3a0 = 0x8041d3a0;
SECTIONS {
  .text.s19_probe_8001744c 0x8001744c : { *(.text.s19_probe_8001744c) }
  .text.s19_forward_8001a02c_80019fb4 0x80019fb4 : { *(.text.s19_forward_8001a02c_80019fb4) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; lbl_804aa6d8 = .;
    . = 0x7080; lbl_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
