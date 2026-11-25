/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_clone_plan_80014a20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80006360 = 0x80006360;
lbl_8036a520 = 0x8036a520;
lbl_8040cdc8 = 0x8040cdc8;
lbl_8040d7b8 = 0x8040d7b8;
SECTIONS {
  .text.w3d_ai_clone_plan_80014a20 0x80014a20 : { *(.text.w3d_ai_clone_plan_80014a20) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
