/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__17D43kTransformNodeUi)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__7D43kPos = 0x80343740;
fn_801b4e94 = 0x801b4e94;
lbl_8041b8c0 = 0x8041b8c0;
lbl_8045e748 = 0x8045e748;
SECTIONS {
  .text.__17D43kTransformNodeUi 0x8024bc08 : { *(.text.__17D43kTransformNodeUi) }
  .rodata 0x803c4540 : { *(.rodata) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
