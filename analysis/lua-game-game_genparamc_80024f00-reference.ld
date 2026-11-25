/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_handle_owner_80024f00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc710 = 0x800fc710;
fn_80178474 = 0x80178474;
fn_80178c48 = 0x80178c48;
fn_801ea910 = 0x801ea910;
fn_80209a44 = 0x80209a44;
fn_80209ae4 = 0x80209ae4;
fn_8020bb2c = 0x8020bb2c;
fn_802105e4 = 0x802105e4;
fn_802ed7e0 = 0x802ed7e0;
fn_803426b4 = 0x803426b4;
fn_80357568 = 0x80357568;
fn_8035d5b4 = 0x8035d5b4;
lbl_8045e0f8 = 0x8045e0f8;
lbl_80462e90 = 0x80462e90;
lbl_80463c04 = 0x80463c04;
SECTIONS {
  .text.w3d_set_handle_owner_80024f00 0x80024f00 : { *(.text.w3d_set_handle_owner_80024f00) }
  .text.w3d_set_handle_owner_8002557c 0x8002557c : { *(.text.w3d_set_handle_owner_8002557c) }
  .text.w3d_set_handle_owner_80025aa0 0x80025aa0 : { *(.text.w3d_set_handle_owner_80025aa0) }
  .text.w3d_dispatch_by_index_801a3e60 0x801a3e60 : { *(.text.w3d_dispatch_by_index_801a3e60) }
  .text.w3d_dispatch_by_index_801a4824 0x801a4824 : { *(.text.w3d_dispatch_by_index_801a4824) }
  .text.w3d_dispatch_by_index_801a4c3c 0x801a4c3c : { *(.text.w3d_dispatch_by_index_801a4c3c) }
  .text.w3d_forward_range_801ae784 0x801ae784 : { *(.text.w3d_forward_range_801ae784) }
  .text.w3d_forward_range_801ae7e4 0x801ae7e4 : { *(.text.w3d_forward_range_801ae7e4) }
  .text.w3d_forward_range_801ae844 0x801ae844 : { *(.text.w3d_forward_range_801ae844) }
  .text.w3d_local_static_801ea954 0x801ea954 : { *(.text.w3d_local_static_801ea954) }
  .text.w3d_local_static_80209a70 0x80209a70 : { *(.text.w3d_local_static_80209a70) }
  .text.w3d_local_static_80210610 0x80210610 : { *(.text.w3d_local_static_80210610) }
  .text.w3d_get_string_802113a0 0x802113a0 : { *(.text.w3d_get_string_802113a0) }
  .text.w3d_get_string_802114b4 0x802114b4 : { *(.text.w3d_get_string_802114b4) }
  .text.w3d_get_string_8021158c 0x8021158c : { *(.text.w3d_get_string_8021158c) }
  .sdata 0x804b0588 (NOLOAD) : {
    . = 0x0; lbl_804b0588 = .;
    . = 0x104; lbl_804b068c = .;
    . = 0x130; lbl_804b06b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
