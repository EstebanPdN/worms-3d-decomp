/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33e_disc_read_retry_801fdcac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fdb98 = 0x801fdb98;
fn_802f5568 = 0x802f5568;
fn_802f7a68 = 0x802f7a68;
fn_802fb7ac = 0x802fb7ac;
lbl_803b1dd8 = 0x803b1dd8;
lbl_803b1dfc = 0x803b1dfc;
tsonnet_c33_poll_dispatch_801fdbec = 0x801fdbec;
w3d_k10b_hold_timeout_801fddac = 0x801fddac;
SECTIONS {
  .text.w3d_d33e_disc_read_retry_801fdcac 0x801fdcac : { *(.text.w3d_d33e_disc_read_retry_801fdcac) }
  .sdata 0x804ab93c (NOLOAD) : {
    . = 0x0; lbl_804ab93c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
