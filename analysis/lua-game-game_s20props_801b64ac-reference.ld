/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801b64ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ecc6c = 0x801ecc6c;
fn_801efd98 = 0x801efd98;
fn_801efff0 = 0x801efff0;
fn_801f2164 = 0x801f2164;
fn_801f2420 = 0x801f2420;
lbl_803ab0f8 = 0x803ab0f8;
lbl_803ab128 = 0x803ab128;
lbl_803ab14c = 0x803ab14c;
lbl_803ab154 = 0x803ab154;
lbl_803ab160 = 0x803ab160;
lbl_8045cf44 = 0x8045cf44;
lbl_8045cf58 = 0x8045cf58;
lbl_8045cf6c = 0x8045cf6c;
lbl_8045cf80 = 0x8045cf80;
lbl_8045e1dc = 0x8045e1dc;
lbl_8045e29c = 0x8045e29c;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed94 = 0x8045ed94;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801b64ac 0x801b64ac : { *(.text.w3d_s20_register_properties_801b64ac) }
  .sdata 0x804b0378 (NOLOAD) : {
    . = 0x0; lbl_804b0378 = .;
    . = 0x4; lbl_804b037c = .;
    . = 0x8; lbl_804b0380 = .;
    . = 0xc; lbl_804b0384 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
