/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_fuse_entity_start_800e8bb0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
attach_800e9b88 = 0x800e9b88;
context_80165254 = 0x80165254;
fn_800e9204 = 0x800e9204;
fn_800e9528 = 0x800e9528;
fn_800e95e0 = 0x800e95e0;
fn_800e962c = 0x800e962c;
fn_800e96a0 = 0x800e96a0;
fn_80164514 = 0x80164514;
forward_8020b680 = 0x8020b680;
fuse_8038b224 = 0x8038b224;
hud_visible_8011afac = 0x8011afac;
identity_80341584 = 0x80341584;
key_80410a10 = 0x80410a10;
kind_8038b1f8 = 0x8038b1f8;
message_id_8015f5a0 = 0x8015f5a0;
origin_8045e788 = 0x8045e788;
read_800fc1b0 = 0x800fc1b0;
scene_800e9e04 = 0x800e9e04;
settings_801797b4 = 0x801797b4;
strcmp = 0x802ef234;
subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d24c_fuse_entity_start_800e8bb0 0x800e8bb0 : { *(.text.d24c_fuse_entity_start_800e8bb0) }
  .sdata 0x804aee58 (NOLOAD) : {
    . = 0x0; c0_804aee58 = .;
    . = 0x8; c1_804aee60 = .;
    . = 0x10; c2_804aee68 = .;
    . = 0x20; c3_804aee78 = .;
    . = 0x28; c4_804aee80 = .;
    . = 0x30; c5_804aee88 = .;
    . = 0x38; c6_804aee90 = .;
    . = 0x40; c8_804aee98 = .;
    . = 0x48; c7_804aeea0 = .;
    . = 0x50; c9_804aeea8 = .;
    . = 0x58; c10_804aeeb0 = .;
    . = 0x2934; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
