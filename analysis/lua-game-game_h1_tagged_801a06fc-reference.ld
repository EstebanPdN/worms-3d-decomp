/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_tagged_construct_8019895c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801f7f1c = 0x801f7f1c;
fn_8035e070 = 0x8035e070;
w3d_auto_8020b648 = 0x8020b648;
w3d_construct_801e6ea8 = 0x801e6ea8;
w3d_construct_801f67e0 = 0x801f67e0;
w3d_float_803a86d0 = 0x803a86d0;
w3d_float_803a9b04 = 0x803a9b04;
w3d_float_803a9b08 = 0x803a9b08;
w3d_float_803a9b0c = 0x803a9b0c;
w3d_float_803a9b10 = 0x803a9b10;
w3d_float_803b0328 = 0x803b0328;
w3d_float_803b032c = 0x803b032c;
w3d_float_803b0404 = 0x803b0404;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_string_default = 0x803426b8;
w3d_string_from_text = 0x8020bb54;
w3d_string_localhost_803b35fc = 0x803b35fc;
w3d_type_80418070 = 0x80418070;
w3d_vtable_80413428 = 0x80413428;
w3d_vtable_80413470 = 0x80413470;
w3d_vtable_804138d0 = 0x804138d0;
w3d_vtable_80413920 = 0x80413920;
w3d_vtable_80416af8 = 0x80416af8;
w3d_vtable_80416b50 = 0x80416b50;
w3d_vtable_80416cc8 = 0x80416cc8;
w3d_vtable_80416d78 = 0x80416d78;
w3d_vtable_804180d8 = 0x804180d8;
w3d_vtable_80418110 = 0x80418110;
w3d_vtable_80418490 = 0x80418490;
w3d_vtable_804192d8 = 0x804192d8;
w3d_vtable_80419510 = 0x80419510;
w3d_vtable_80419540 = 0x80419540;
w3d_vtable_80419668 = 0x80419668;
w3d_vtable_80419688 = 0x80419688;
w3d_vtable_80419700 = 0x80419700;
SECTIONS {
  .text.w3d_tagged_construct_8019895c 0x8019895c : { *(.text.w3d_tagged_construct_8019895c) }
  .text.w3d_tagged_construct_801a06fc 0x801a06fc : { *(.text.w3d_tagged_construct_801a06fc) }
  .text.w3d_tagged_construct_801de81c 0x801de81c : { *(.text.w3d_tagged_construct_801de81c) }
  .text.w3d_tagged_construct_801dfbd4 0x801dfbd4 : { *(.text.w3d_tagged_construct_801dfbd4) }
  .text.w3d_tagged_construct_801f83b4 0x801f83b4 : { *(.text.w3d_tagged_construct_801f83b4) }
  .text.w3d_tagged_construct_802084f8 0x802084f8 : { *(.text.w3d_tagged_construct_802084f8) }
  .text.w3d_tagged_construct_8020dfdc 0x8020dfdc : { *(.text.w3d_tagged_construct_8020dfdc) }
  .text.w3d_tagged_construct_802110cc 0x802110cc : { *(.text.w3d_tagged_construct_802110cc) }
  .sdata 0x804ab834 (NOLOAD) : {
    . = 0x0; w3d_sda_owner_804ab834 = .;
    . = 0x60c8; w3d_sda_network_804b18fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
