/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__12Top_80411248)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12Sub_802109dc = 0x802109dc;
_vt.12Mid_804112e0 = 0x804112e0;
_vt.12Top_80411248 = 0x80411248;
_vt.13Node_80411378 = 0x80411378;
desc_80412790 = 0x80412790;
forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.__12Top_80411248 0x8015db40 : { *(.text.__12Top_80411248) }
  .rodata 0x803a44ac : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
