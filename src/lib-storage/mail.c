/* Copyright (C) 2002-2003 Timo Sirainen */

#include "lib.h"
#include "ioloop.h"
#include "mail-storage-private.h"

struct mail *mail_alloc(struct mailbox_transaction_context *t,
			enum mail_fetch_field wanted_fields,
			struct mailbox_header_lookup_ctx *wanted_headers)
{
	return t->box->v.mail_alloc(t, wanted_fields, wanted_headers);
}

void mail_free(struct mail *mail)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.free(mail);
}

int mail_set_seq(struct mail *mail, uint32_t seq)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.set_seq(mail, seq);
}

enum mail_flags mail_get_flags(struct mail *mail)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_flags(mail);
}

const char *const *mail_get_keywords(struct mail *mail)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_keywords(mail);
}

const struct message_part *mail_get_parts(struct mail *mail)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_parts(mail);
}

time_t mail_get_received_date(struct mail *mail)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_received_date(mail);
}

time_t mail_get_date(struct mail *mail, int *timezone)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_date(mail, timezone);
}

uoff_t mail_get_virtual_size(struct mail *mail)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_virtual_size(mail);
}

uoff_t mail_get_physical_size(struct mail *mail)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_physical_size(mail);
}

const char *mail_get_first_header(struct mail *mail, const char *field)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_first_header(mail, field);
}

const char *const *mail_get_headers(struct mail *mail, const char *field)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_headers(mail, field);
}

struct istream *
mail_get_header_stream(struct mail *mail,
		       struct mailbox_header_lookup_ctx *headers)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_header_stream(mail, headers);
}

struct istream *mail_get_stream(struct mail *mail,
				struct message_size *hdr_size,
				struct message_size *body_size)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_stream(mail, hdr_size, body_size);
}

const char *mail_get_special(struct mail *mail, enum mail_fetch_field field)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.get_special(mail, field);
}

int mail_update_flags(struct mail *mail, enum modify_type modify_type,
		      enum mail_flags flags)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.update_flags(mail, modify_type, flags);
}

int mail_update_keywords(struct mail *mail, enum modify_type modify_type,
			 struct mail_keywords *keywords)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.update_keywords(mail, modify_type, keywords);
}

int mail_expunge(struct mail *mail)
{
	struct mail_private *p = (struct mail_private *)mail;

	return p->v.expunge(mail);
}
