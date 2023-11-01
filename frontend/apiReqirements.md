# Backend API Requirements

## Introduction

This document outlines the requirements for the backend API that the frontend will rely on. It describes the endpoints, request parameters, and expected JSON responses for each endpoint.

## API Base URL

- Base URL: `https://api.example.com`

## Endpoints

### 1. Homepage

- **Endpoint:** `/Homepage`
- **Method:** GET

**Response:**

```json
{
  "Github": "https//github.com/username",
  "Documentatiom": "https//documentatiom.com",
  "Team": [
    {
      "name": "name",
      "email": "email",
      "github": "github"
    },
    {
      "name": "name",
      "email": "email",
      "github": "github"
    }
  
  ]
}
```

### 2. Manager page

- **Endpoint:** `/manager`
- **Method:** GET

**Response:**

```json
{
  "privatetables": [
    {
      "table_id": 1,
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    },
    {
      "table_id": 2,
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    },
    {
      "table_id": 3,
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    }
  ],
  "generaltables" :[
    {
      "table_id": 1,
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    },
    {
      "table_id": 2,
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    },
    {
      "table_id": 3,
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    }
  ],
  "do_rounds": [
    {
      "waiter_id": "waiter_id",
      "table_type" : "table_type",
      "table_to_check" : "table_id",
      "customer_status": "customer_status" //im referring to what emotion they have.
    },
    {
      "waiter_id": "waiter_id",
      "table_type" : "table_type",
      "table_to_check" : "table_id",
      "customer_status": "customer_status"
    },
    {
      "waiter_id": "waiter_id",
      "table_type" : "table_type",
      "table_to_check" : "table_id",
      "customer_status": "customer_status"
    }
  ],
  "buy_ingredients":[
    {
      "ingredient_id": 1,
      "ingredient_name": "ingredient_name",
      "price" : 19.99
    },
    {
      "ingredient_id": 1,
      "ingredient_name": "ingredient_name",
      "price" : 22.50
    },
    {
      "ingredient_id": 1,
      "ingredient_name": "ingredient_name",
      "price" : 30.99
    },
    {
      "ingredient_id": 1,
      "ingredient_name": "ingredient_name",
      "price" : 45.00
    }
  ],
  "send_waiter": {
    "waiter_id": "waiter_id",
    "table_type" : "table_type",
    "table_to_check" : "table_id",
    "customer_status": "customer_status"
  },
  "Balance": "user123" 

}
```

### 3. Ordering

- **Endpoint:** `/Ordering`
- **Method:** GET

**Response:**

```json
[
  {
    "item_id": 1,
    "name": "Item 1",
    "price": 19.99
  },
  {
    "item_id": 2,
    "name": "Item 2",
    "price": 29.99
  }
]
```

### 4. Customer Page

- **Endpoint:** `/Ordering`
- **Method:** GET
**Response:**

```json
[
  {

  }
]
```
