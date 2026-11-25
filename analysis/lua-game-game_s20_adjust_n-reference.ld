/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_dispatch_all_targets_801aa79c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a9cbc = 0x801a9cbc;
SECTIONS {
  .text.w3d_s20_dispatch_all_targets_801aa79c 0x801aa79c : { *(.text.w3d_s20_dispatch_all_targets_801aa79c) }
  .text.w3d_s20_dispatch_item_targets_801aa8cc 0x801aa8cc : { *(.text.w3d_s20_dispatch_item_targets_801aa8cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
