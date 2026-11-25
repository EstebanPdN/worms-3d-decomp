/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_dispatch_kind_801a42fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a4278 = 0x801a4278;
fn_801c90c0 = 0x801c90c0;
fn_801d6000 = 0x801d6000;
fn_801d6644 = 0x801d6644;
fn_801f55ec = 0x801f55ec;
lbl_80363938 = 0x80363938;
lbl_803af55c = 0x803af55c;
lbl_80416348 = 0x80416348;
SECTIONS {
  .text.w3d_s20_dispatch_kind_801a42fc 0x801a42fc : { *(.text.w3d_s20_dispatch_kind_801a42fc) }
  .text.w3d_s20_set_block_and_forward_801a5650 0x801a5650 : { *(.text.w3d_s20_set_block_and_forward_801a5650) }
  .text.w3d_s20_construct_with_global_801c98b8 0x801c98b8 : { *(.text.w3d_s20_construct_with_global_801c98b8) }
  .text.w3d_s20_warn_if_empty_801d66d8 0x801d66d8 : { *(.text.w3d_s20_warn_if_empty_801d66d8) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
