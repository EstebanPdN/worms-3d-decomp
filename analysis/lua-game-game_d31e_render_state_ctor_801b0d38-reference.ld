/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__6Render)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__7FullTag = 0x801e81c8;
__vt_5Iface = 0x804136c0;
__vt_6Render = 0x80414220;
k_804143e0 = 0x804143e0;
k_80415bb0 = 0x80415bb0;
k_80415c00 = 0x80415c00;
k_80415cb0 = 0x80415cb0;
k_804166b0 = 0x804166b0;
w3d_auto_8020b648 = 0x8020b648;
w3d_s10_service_forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.__6Render 0x801b0d38 : { *(.text.__6Render) }
  .rodata 0x803aa838 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
