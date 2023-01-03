CREATE EXTENSION bytea_bitops;

SELECT bytea_xor('\xDEAD','\xBEEF');
SELECT bytea_and('\xDEAD','\xBEEF');
SELECT bytea_or('\xDEAD','\xBEEF');
SELECT bytea_not('\xDEADBEEF');

SELECT '\xDEAD'::bytea # '\xBEEF';
SELECT '\xDEAD'::bytea & '\xBEEF';
SELECT '\xDEAD'::bytea | '\xBEEF';
SELECT ~ '\xDEADBEEF'::bytea;
