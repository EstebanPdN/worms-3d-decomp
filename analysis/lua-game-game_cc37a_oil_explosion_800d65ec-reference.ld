/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc37a_oil_explosion_800d65ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc37a_alloc_801613f0 = 0x801613f0;
cc37a_damage_80388eb0 = 0x80388eb0;
cc37a_effect_800e5ca4 = 0x800e5ca4;
cc37a_effect_80388f34 = 0x80388f34;
cc37a_explosion_800666b4 = 0x800666b4;
cc37a_impulse_80388ec8 = 0x80388ec8;
cc37a_land_80388f00 = 0x80388f00;
cc37a_offset_80388f60 = 0x80388f60;
cc37a_post_8016239c = 0x8016239c;
cc37a_radius_80388f1c = 0x80388f1c;
cc37a_read_800fc270 = 0x800fc270;
cc37a_scale_80388f64 = 0x80388f64;
cc37a_sound_80388f4c = 0x80388f4c;
cc37a_worm_80388ee4 = 0x80388ee4;
SECTIONS {
  .text.cc37a_oil_explosion_800d65ec 0x800d65ec : { *(.text.cc37a_oil_explosion_800d65ec) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; cc37a_messages_804b1754 = .;
    . = 0x34; cc37a_services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
