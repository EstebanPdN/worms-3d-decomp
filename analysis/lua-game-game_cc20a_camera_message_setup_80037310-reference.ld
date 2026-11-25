/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc20a_camera_message_setup_80037310)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800d308c = 0x800d308c;
fn_800d31d8 = 0x800d31d8;
fn_800fc230 = 0x800fc230;
fn_800fc2b0 = 0x800fc2b0;
fn_8010a8e0 = 0x8010a8e0;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
lbl_80373da4 = 0x80373da4;
lbl_80373dbc = 0x80373dbc;
lbl_80373dc8 = 0x80373dc8;
lbl_80373dd0 = 0x80373dd0;
lbl_80373ddc = 0x80373ddc;
lbl_80373de8 = 0x80373de8;
lbl_80373e00 = 0x80373e00;
lbl_80373e10 = 0x80373e10;
lbl_80373e1c = 0x80373e1c;
SECTIONS {
  .text.w3d_cc20a_camera_message_setup_80037310 0x80037310 : { *(.text.w3d_cc20a_camera_message_setup_80037310) }
  .sdata 0x804ad030 (NOLOAD) : {
    . = 0x0; lbl_804ad030 = .;
    . = 0x8; lbl_804ad038 = .;
    . = 0x4724; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
