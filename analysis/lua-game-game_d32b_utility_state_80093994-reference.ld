/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__16D32bUtilityState)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13D32bActorBase = 0x8002a914;
_vt.16D32bUtilityState = 0x8040f1f8;
SECTIONS {
  .text.__16D32bUtilityState 0x80093994 : { *(.text.__16D32bUtilityState) }
  .rodata 0x8037ea0c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
