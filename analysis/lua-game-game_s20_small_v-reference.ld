/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_destroy_pooled_800e7344)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800e5cf0 = 0x800e5cf0;
fn_800e77dc = 0x800e77dc;
fn_8015a39c = 0x8015a39c;
fn_80167018 = 0x80167018;
fn_80209920 = 0x80209920;
lbl_8039fc00 = 0x8039fc00;
lbl_8039fc08 = 0x8039fc08;
lbl_8039fc1c = 0x8039fc1c;
lbl_8039fc24 = 0x8039fc24;
lbl_80410138 = 0x80410138;
SECTIONS {
  .text.w3d_s20_destroy_pooled_800e7344 0x800e7344 : { *(.text.w3d_s20_destroy_pooled_800e7344) }
  .text.w3d_s20_bind_names_8013e35c 0x8013e35c : { *(.text.w3d_s20_bind_names_8013e35c) }
  .text.w3d_s20_flush_pending_80167094 0x80167094 : { *(.text.w3d_s20_flush_pending_80167094) }
  .sdata 0x804b0044 (NOLOAD) : {
    . = 0x0; lbl_804b0044 = .;
    . = 0x98; lbl_804b00dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
