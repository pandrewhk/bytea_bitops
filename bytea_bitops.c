/*
 * bytea_bitops.c
 *
 * Adding bytea bit operation functions similar to varbit's bit operations.
 *
 * Copyright (c) 2018, Christian Rossow
 * Copyright (c) 2023, Andrew Pantyukhin <infofarmer@FreeBSD.org>
 *
 * License: PostgreSQL
 *
 */

#include "postgres.h"
#include "fmgr.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(bytea_xor);
Datum bytea_xor(PG_FUNCTION_ARGS)
{
	bytea*	ba1 = PG_GETARG_BYTEA_P(0);
	bytea*	ba2 = PG_GETARG_BYTEA_P(1);
	bytea*	result;
	char*	str1 = VARDATA(ba1);
	char*	str2 = VARDATA(ba2);
	char*	resstr;
	int32	len;
	int32	i;

	if (VARSIZE(ba1) != VARSIZE(ba2))
	{
		ereport(ERROR,
				(errcode(ERRCODE_STRING_DATA_LENGTH_MISMATCH),
				 errmsg("cannot XOR bytea of different sizes")));
	}

	len = VARSIZE(ba1);
	result = (bytea *) palloc(len);
	SET_VARSIZE(result, len);

	resstr = VARDATA(result);
	for (i=0; i < len - VARHDRSZ; ++i)
	{
		resstr[i] = str1[i] ^ str2[i];
	}

	PG_RETURN_BYTEA_P(result);
}

PG_FUNCTION_INFO_V1(bytea_and);
Datum bytea_and(PG_FUNCTION_ARGS)
{
	bytea*	ba1 = PG_GETARG_BYTEA_P(0);
	bytea*	ba2 = PG_GETARG_BYTEA_P(1);
	bytea*	result;
	char*	str1 = VARDATA(ba1);
	char*	str2 = VARDATA(ba2);
	char*	resstr;
	int32	len;
	int32	i;

	if (VARSIZE(ba1) != VARSIZE(ba2))
	{
		ereport(ERROR,
				(errcode(ERRCODE_STRING_DATA_LENGTH_MISMATCH),
				 errmsg("cannot AND bytea of different sizes")));
	}

	len = VARSIZE(ba1);
	result = (bytea *) palloc(len);
	SET_VARSIZE(result, len);

	resstr = VARDATA(result);
	for (i=0; i < len - VARHDRSZ; ++i)
	{ 
	resstr[i] = str1[i] & str2[i];
	}

	PG_RETURN_BYTEA_P(result);
}

PG_FUNCTION_INFO_V1(bytea_or);
Datum bytea_or(PG_FUNCTION_ARGS)
{
	bytea*	ba1 = PG_GETARG_BYTEA_P(0);
	bytea*	ba2 = PG_GETARG_BYTEA_P(1);
	bytea*	result;
	char*	str1 = VARDATA(ba1);
	char*	str2 = VARDATA(ba2);
	char*	resstr;
	int32	len;
	int32	i;

	if (VARSIZE(ba1) != VARSIZE(ba2))
	{
		ereport(ERROR,
				(errcode(ERRCODE_STRING_DATA_LENGTH_MISMATCH),
				 errmsg("cannot AND bytea of different sizes")));
	}

	len = VARSIZE(ba1);
	result = (bytea *) palloc(len);
	SET_VARSIZE(result, len);

	resstr = VARDATA(result);
	for (i=0; i < len - VARHDRSZ; ++i)
	{
		resstr[i] = str1[i] | str2[i];
	}

	PG_RETURN_BYTEA_P(result);
}

PG_FUNCTION_INFO_V1(bytea_not);
Datum bytea_not(PG_FUNCTION_ARGS)
{
	bytea*	ba1 = PG_GETARG_BYTEA_P(0);
	bytea*	result;
	char*	str1 = VARDATA(ba1);
	char*	resstr;
	int32	len = VARSIZE(ba1);
	int32	i;

	result = (bytea *) palloc(len);
	SET_VARSIZE(result, len);

	resstr = VARDATA(result);
	for (i=0; i < len - VARHDRSZ; ++i)
	{
		resstr[i] = ~str1[i];
	}

	PG_RETURN_BYTEA_P(result);
}
