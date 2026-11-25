/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_apply_item_targets_8016bafc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ace68 = 0x801ace68;
fn_801ad060 = 0x801ad060;
fn_801ad0e4 = 0x801ad0e4;
fn_801ad168 = 0x801ad168;
SECTIONS {
  .text.w3d_s20_apply_item_targets_8016bafc 0x8016bafc : { *(.text.w3d_s20_apply_item_targets_8016bafc) }
  .text.w3d_s20_commit_item_801ad590 0x801ad590 : { *(.text.w3d_s20_commit_item_801ad590) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
