import React from 'react';
import { BrowserRouter, Routes, Route } from 'react-router-dom';

import { purple, orange } from '@mui/material/colors';
import { createTheme, CssBaseline, ThemeProvider } from '@mui/material';

import Start from './pages/Start/Start';
import Staff from './pages/Staff/Staff';
import Customer from './pages/Customer/Customer';
import NotFound from './pages/NotFound/NotFound';
import Order from './pages/Customer/Order'; 
import Payment from './pages/Customer/Payment';

function App() {
  const theme = createTheme({
    palette: {
      mode: 'dark',
      primary: {
        main: purple[600]
      },
      secondary: {
        main: orange[600]
      }
    },
    components: {
      MuiTabs: {
        styleOverrides: {
          flexContainer: {
            justifyContent: 'center'
          }
        }
      }
    }
  });

  return (
    <BrowserRouter>
      <ThemeProvider theme={theme}>
        <CssBaseline />
        <Routes>
          <Route path='/' element={<Start />} />
          <Route path='*' element={<NotFound />} />
          <Route index path='/staff' element={<Staff />} />
          <Route index path='/customer' element={<Customer />} />
          <Route index path='/team' element={<Team />} />
          <Route path="order" element={<Order />} /> 
          <Route path="payment" element={<Payment />} />
        </Routes>
      </ThemeProvider>
    </BrowserRouter>
  );
}

export default App;
