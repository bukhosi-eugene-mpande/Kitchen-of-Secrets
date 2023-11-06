import React, { useContext } from 'react';

import { CookContext } from './Cook';

import {
    Box,
    List,
    Button,
    Divider,
    ListItem,
    Typography,
    ListItemText
} from '@mui/material';

import data from '../../../data/data.json';

function Ingredients() {
  const ingredients = data.ingredients;
  const { addToPot } = useContext(CookContext);

  return (
    <Box
      sx={{
        m: 2,
        p: 2,
        width: '100%',
        maxHeight: 500,
        borderRadius: '4px',
        border: '4px solid',
        justifyContent: 'center',
        borderColor: 'primary.main',
        overflow: 'scroll'
      }}
    >
      <Typography variant='h3'>Ingredients</Typography>

      <Divider sx={{ my: 2 }} />

      <List>
        {ingredients.map((ingredient, index) => (
          <ListItem key={index}>
            <ListItemText primary={ingredient} sx={{ textAlign: 'center' }} />

            <Button
              size='small'
              variant='contained'
              onClick={() => addToPot(ingredient)}
            >
              Add
            </Button>
          </ListItem>
        ))}
      </List>
    </Box>
  );
}

export default Ingredients;
