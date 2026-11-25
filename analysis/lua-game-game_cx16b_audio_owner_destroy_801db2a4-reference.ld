/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16b_audio_owner_destroy_801db2a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801daf5c = 0x801daf5c;
fn_801dc6d8 = 0x801dc6d8;
fn_801de574 = 0x801de574;
fn_801fe1f8 = 0x801fe1f8;
fn_80210990 = 0x80210990;
fn_80210abc = 0x80210abc;
fn_802134fc = 0x802134fc;
fn_80331a40 = 0x80331a40;
lbl_804168c0 = 0x804168c0;
lbl_80416970 = 0x80416970;
SECTIONS {
  .text.w3d_cx16b_audio_owner_destroy_801db2a4 0x801db2a4 : { *(.text.w3d_cx16b_audio_owner_destroy_801db2a4) }
  .sdata 0x804ab80c (NOLOAD) : {
    . = 0x0; lbl_804ab80c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
