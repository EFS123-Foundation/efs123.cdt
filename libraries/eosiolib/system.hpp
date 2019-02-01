/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include "system.h"
#include <alloca.h>
#include <string>

#warning "<eosiolib/system.hpp> is deprecated use <eosio/system.hpp>"

namespace eosio {
   /**
    *  @addtogroup system System C++ API
    *  @ingroup cpp_api
    *  @brief Defines wrappers over eosio_assert 
    *
    *  @{
    */

   /**
    *
    *  @brief Assert if the predicate fails and use the supplied message.
    *
    *  Example:
    *
    *  @code
    *  eosio::check(a == b, "a does not equal b");
    *  @endcode
    */
   inline void check(bool pred, const char* msg) {
      if (!pred) {
         internal_use_do_not_use::eosio_assert(false, msg);
      }
   }

    /**
    *
    *  @brief Assert if the predicate fails and use the supplied message.
    *
    *  Example:
    *
    *  @code
    *  eosio::check(a == b, "a does not equal b");
    *  @endcode
    */
   inline void check(bool pred, const std::string& msg) {
      if (!pred) {
         internal_use_do_not_use::eosio_assert(false, msg.c_str());
      }
   }

   /**
    *
    *  @brief Assert if the predicate fails and use the supplied message.
    *
    *  Example:
    *
    *  @code
    *  eosio::check(a == b, "a does not equal b");
    *  @endcode
    */
   inline void check(bool pred, std::string&& msg) {
      if (!pred) {
         internal_use_do_not_use::eosio_assert(false, msg.c_str());
      }
   }

   /**
    *
    *  @brief Assert if the predicate fails and use a subset of the supplied message.
    *
    *  Example:
    *
    *  @code
    *  const char* msg = "a does not equal b b does not equal a";
    *  eosio::check(a == b, "a does not equal b", 18);
    *  @endcode
    */
   inline void check(bool pred, const char* msg, size_t n) {
      if (!pred) {
         internal_use_do_not_use::eosio_assert_message(false, msg, n);
      }
   }

   /**
    *
    *  @brief Assert if the predicate fails and use a subset of the supplied message.
    *
    *  Example:
    *
    *  @code
    *  std::string msg = "a does not equal b b does not equal a";
    *  eosio::check(a == b, msg, 18);
    *  @endcode
    */
   inline void check(bool pred, const std::string& msg, size_t n) {
      if (!pred) {
         internal_use_do_not_use::eosio_assert_message(false, msg.c_str(), n);
      }
   }

    /**
    *
    *  @brief Assert if the predicate fails and use the supplied error code.
    *
    *  Example:
    *
    *  @code
    *  eosio::check(a == b, 13);
    *  @endcode
    */
   inline void check(bool pred, uint64_t code) {
      if (!pred) {
         internal_use_do_not_use::eosio_assert_code(false, code);
      }
   }

     /**
    *  This method will abort execution of wasm without failing the contract. This is used to bypass all cleanup / destructors that would normally be called.
    *
    *  @param code - the exit code
    *  Example:
    *
    *  @code
    *  eosio_exit(0);
    *  eosio_exit(1);
    *  eosio_exit(2);
    *  eosio_exit(3);
    *  @endcode
    */
   inline void eosio_exit( int32_t code ) {
      internal_use_do_not_use::eosio_exit(code);
   }

   /**
    *  Returns the time in microseconds from 1970 of the current block
    *
    *  @return time in microseconds from 1970 of the current block
    */
   inline uint64_t  current_time() {
      return internal_use_do_not_use::current_time();
   }

    /**
    *  Get time (rounded down to the nearest second) of the current block (i.e. the block including this action)
    *
    *  @return time in seconds from 1970 of the current block
    */
  inline uint32_t  now() {
      return (uint32_t)( current_time() / 1000000 );
   }

} // namespace eosio
   /// @}