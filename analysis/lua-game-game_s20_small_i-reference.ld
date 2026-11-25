/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_forward_global_800e5ca4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a4d3c = 0x800a4d3c;
fn_800ddfe4 = 0x800ddfe4;
fn_800de16c = 0x800de16c;
fn_800e5da0 = 0x800e5da0;
fn_80164fc8 = 0x80164fc8;
fn_801e8d9c = 0x801e8d9c;
fn_801ecab4 = 0x801ecab4;
lbl_803ab810 = 0x803ab810;
SECTIONS {
  .text.w3d_s20_forward_global_800e5ca4 0x800e5ca4 : { *(.text.w3d_s20_forward_global_800e5ca4) }
  .text.w3d_s20_call_with_swapped_800e7114 0x800e7114 : { *(.text.w3d_s20_call_with_swapped_800e7114) }
  .text.w3d_s20_call_with_swapped_800e7160 0x800e7160 : { *(.text.w3d_s20_call_with_swapped_800e7160) }
  .text.w3d_s20_forward_handle_8013dda8 0x8013dda8 : { *(.text.w3d_s20_forward_handle_8013dda8) }
  .text.w3d_s20_reset_named_801bc430 0x801bc430 : { *(.text.w3d_s20_reset_named_801bc430) }
  .sdata 0x804aaecc (NOLOAD) : {
    . = 0x0; lbl_804aaecc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
