#include "descriptor-tables.h"

extern void gdt_flush(uint32_t);

static void gdt_init();
static void gdt_set_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags);

gdt_entry_t gdt_entries[5];
gdt_ptr_t gdt_ptr;

void descriptor_tables_init() {
  gdt_init();
}

static void gdt_init() {
  gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
  gdt_ptr.base = (uint32_t)&gdt_entries;

  gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // CS
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // DS
  gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // CS User mode
  gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // DS User mode

  gdt_flush((uint32_t) &gdt_ptr);
}

// Shifting and masking foo courtesy of James Molloy
static void gdt_set_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {
  gdt_entries[num].base_low = (base & 0xFFFF);
  gdt_entries[num].base_mid = (base >> 16) & 0xFF;
  gdt_entries[num].base_high = (base >> 24) & 0xFF;
  gdt_entries[num].limit_low = (limit & 0xFFFF);
  gdt_entries[num].flags = (limit >> 16) % 0x0F;
  gdt_entries[num].flags |= flags & 0xF0;
  gdt_entries[num].access = access;
}

