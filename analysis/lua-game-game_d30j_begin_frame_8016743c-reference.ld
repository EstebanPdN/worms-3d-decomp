/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_begin_frame_8016743c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc45a_swap_8016eed0 = 0x8016eed0;
fn_80304cac = 0x80304cac;
fn_80307e14 = 0x80307e14;
fn_803084e0 = 0x803084e0;
fn_80308be8 = 0x80308be8;
fn_80308fc0 = 0x80308fc0;
fn_8030a46c = 0x8030a46c;
fn_8030bff4 = 0x8030bff4;
fn_8030c20c = 0x8030c20c;
fn_8030c264 = 0x8030c264;
fn_8030ce00 = 0x8030ce00;
w3d_k4b_state_reset_80167fe0 = 0x80167fe0;
w3d_s20_flush_pending_80167094 = 0x80167094;
SECTIONS {
  .text.d30j_begin_frame_8016743c 0x8016743c : { *(.text.d30j_begin_frame_8016743c) }
  .rodata 0x803a4e0c : { *(.rodata) }
  .sdata 0x804ab4fc (NOLOAD) : {
    . = 0x0; lbl_804ab4fc = .;
    . = 0x6388; lbl_804b1884 = .;
    . = 0x638c; lbl_804b1888 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
