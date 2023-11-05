import React from 'react';

import { Box } from '@mui/material';

function Panel({ children, value, index }) {
  return (
    <Box
      hidden={value !== index}
    >
      {children}
    </Box>
  );
}

export default Panel;
