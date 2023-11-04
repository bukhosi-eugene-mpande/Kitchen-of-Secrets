import React from 'react';

import Grid from '@mui/material/Unstable_Grid2';
import { Box, List, Divider, ListItem, ListItemText, Typography } from '@mui/material';

import data from '../../../data/data.json';

function Instructions({ order }) {
  const { requiredIngredients } = data;

  return (
    <Box
      sx={{
        m: 2,
        p: 2,
        width: '60%',
        border: '4px solid',
        borderRadius: '4px',
        borderColor: 'primary.main'
      }}
    >
      <Typography variant='h5' sx={{ mb: 2, textAlign: 'center' }}>
      Ingredients for Table-{order.table} order
      </Typography>

      <Divider sx={{ mb: 2 }} />

      <Grid container spacing={2} sx={{ textAlign: 'center' }}>
        {order.food.map((foodItem, i) => {
          const requiredFoodItem = requiredIngredients.find(
            (item) => item.name === foodItem
          );

          return (
            <Grid item xs={4} key={i}>
              <Typography variant='h6'>
                {requiredFoodItem.name}
              </Typography>

              <List>
                {requiredFoodItem.ingredients.map((ingredient, j) => (
                  <ListItem key={j}>
                    <ListItemText
                      primary={ingredient}
                      sx={{ textAlign: 'center' }}
                    />
                  </ListItem>
                ))}
              </List>
            </Grid>
          );
        })}

        <Grid item xs={4}>
          <Typography variant='h6'>Beverages</Typography>

          <List>
            {order.beverages.map((beverage, index) => (
              <ListItem key={index}>
                <ListItemText primary={beverage} sx={{ textAlign: 'center' }} />
              </ListItem>
            ))}
          </List>
        </Grid>
      </Grid>
    </Box>
  );
}

export default Instructions;
