MODULES = bytea_bitops

EXTENSION = bytea_bitops
DATA = bytea_bitops--0.1.sql
PGFILEDESC = "bytea_bitops - bitwise operators for bytea"

REGRESS = bytea_bitops

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
