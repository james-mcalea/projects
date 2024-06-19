import React from "react";
import { Input, Stack, Checkbox, CheckboxGroup } from "@chakra-ui/react";
import {
  FormControl,
  FormLabel,
  FormErrorMessage,
  FormHelperText,
} from "@chakra-ui/react";

const Test = () => {
  <FormControl>
    <FormLabel>Email address</FormLabel>
    <Input type="email" />
    <FormHelperText>We'll never share your email.</FormHelperText>
  </FormControl>;
};

export default Test;
