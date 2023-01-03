CREATE OR REPLACE FUNCTION bytea_xor(bytea, bytea) RETURNS bytea
AS 'bytea_bitops.so', 'bytea_xor'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;

CREATE OPERATOR # (LEFTARG = bytea, RIGHTARG = bytea, FUNCTION = bytea_xor);

CREATE OR REPLACE FUNCTION bytea_and(bytea, bytea) RETURNS bytea
AS 'bytea_bitops.so', 'bytea_and'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;

CREATE OPERATOR & (LEFTARG = bytea, RIGHTARG = bytea, FUNCTION = bytea_and);

CREATE OR REPLACE FUNCTION bytea_or(bytea, bytea) RETURNS bytea
AS 'bytea_bitops.so', 'bytea_or'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;

CREATE OPERATOR | (LEFTARG = bytea, RIGHTARG = bytea, FUNCTION = bytea_or);

CREATE OR REPLACE FUNCTION bytea_not(bytea) RETURNS bytea
AS 'bytea_bitops.so', 'bytea_not'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;

CREATE OPERATOR ~ (RIGHTARG = bytea, FUNCTION = bytea_not);
