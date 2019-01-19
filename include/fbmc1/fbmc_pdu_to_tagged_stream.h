/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_FBMC1_FBMC_PDU_TO_TAGGED_STREAM_H
#define INCLUDED_FBMC1_FBMC_PDU_TO_TAGGED_STREAM_H

#include <fbmc1/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace fbmc1 {

    /*!
     * \brief <+description of block+>
     * \ingroup fbmc1
     *
     */
    class FBMC1_API fbmc_pdu_to_tagged_stream : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<fbmc_pdu_to_tagged_stream> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of fbmc1::fbmc_pdu_to_tagged_stream.
       *
       * To avoid accidental use of raw pointers, fbmc1::fbmc_pdu_to_tagged_stream's
       * constructor is in a private implementation
       * class. fbmc1::fbmc_pdu_to_tagged_stream::make is the public interface for
       * creating new instances.
       */
      static sptr make(int veclength, int microseconds);
    };

  } // namespace fbmc1
} // namespace gr

#endif /* INCLUDED_FBMC1_FBMC_PDU_TO_TAGGED_STREAM_H */
