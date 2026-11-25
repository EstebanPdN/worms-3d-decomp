/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc20a_particle_arenas_sinit_800e0450)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__19Cc20aArena_802097ecPCcii = 0x802097ec;
fn_802ee7dc = 0x802ee7dc;
lbl_80389d44 = 0x80389d44;
lbl_80389d54 = 0x80389d54;
lbl_80389d64 = 0x80389d64;
lbl_80389d68 = 0x80389d68;
lbl_804453c8 = 0x804453c8;
SECTIONS {
  .text.w3d_cc20a_particle_arenas_sinit_800e0450 0x800e0450 : { *(.text.w3d_cc20a_particle_arenas_sinit_800e0450) }
  .sdata 0x804aae9c (NOLOAD) : {
    . = 0x0; lbl_804aae9c = .;
    . = 0x3de4; lbl_804aec80 = .;
    . = 0x3de8; lbl_804aec84 = .;
    . = 0x3dec; lbl_804aec88 = .;
    . = 0x3df0; lbl_804aec8c = .;
    . = 0x3df4; lbl_804aec90 = .;
    . = 0x3df8; lbl_804aec94 = .;
    . = 0x3dfc; lbl_804aec98 = .;
    . = 0x3e00; lbl_804aec9c = .;
    . = 0x3e04; lbl_804aeca0 = .;
    . = 0x3e08; lbl_804aeca4 = .;
    . = 0x3e10; lbl_804aecac = .;
    . = 0x3e18; lbl_804aecb4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
