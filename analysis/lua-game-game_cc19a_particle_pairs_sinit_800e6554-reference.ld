/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc19a_particle_pairs_sinit_800e6554)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800e4ff8 = 0x800e4ff8;
fn_8015f518 = 0x8015f518;
fn_801629f8 = 0x801629f8;
lbl_80360d80 = 0x80360d80;
lbl_803618f0 = 0x803618f0;
lbl_8038aec0 = 0x8038aec0;
lbl_8038aed8 = 0x8038aed8;
lbl_8038aeec = 0x8038aeec;
lbl_8038af04 = 0x8038af04;
lbl_8038af18 = 0x8038af18;
lbl_8038af30 = 0x8038af30;
lbl_8038af48 = 0x8038af48;
lbl_8038af64 = 0x8038af64;
lbl_8038af7c = 0x8038af7c;
lbl_8038af80 = 0x8038af80;
lbl_8038af84 = 0x8038af84;
lbl_8038af88 = 0x8038af88;
lbl_8038af8c = 0x8038af8c;
lbl_803e81e8 = 0x803e81e8;
lbl_80447424 = 0x80447424;
lbl_80447430 = 0x80447430;
lbl_8044743c = 0x8044743c;
lbl_80447448 = 0x80447448;
SECTIONS {
  .text.w3d_cc19a_particle_pairs_sinit_800e6554 0x800e6554 : { *(.text.w3d_cc19a_particle_pairs_sinit_800e6554) }
  .sdata 0x804aaec4 (NOLOAD) : {
    . = 0x0; lbl_804aaec4 = .;
    . = 0x3ec4; lbl_804aed88 = .;
    . = 0x3ec8; lbl_804aed8c = .;
    . = 0x3ecc; lbl_804aed90 = .;
    . = 0x3ed0; lbl_804aed94 = .;
    . = 0x3ed4; lbl_804aed98 = .;
    . = 0x3ed8; lbl_804aed9c = .;
    . = 0x3edc; lbl_804aeda0 = .;
    . = 0x3ee0; lbl_804aeda4 = .;
    . = 0x3ee4; lbl_804aeda8 = .;
    . = 0x3ee8; lbl_804aedac = .;
    . = 0x3ef0; lbl_804aedb4 = .;
    . = 0x3ef8; lbl_804aedbc = .;
    . = 0x3f00; lbl_804aedc4 = .;
    . = 0x3f08; lbl_804aedcc = .;
    . = 0x3f10; lbl_804aedd4 = .;
    . = 0x3f18; lbl_804aeddc = .;
    . = 0x3f20; lbl_804aede4 = .;
    . = 0x3f28; lbl_804aedec = .;
    . = 0x3f30; lbl_804aedf4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
